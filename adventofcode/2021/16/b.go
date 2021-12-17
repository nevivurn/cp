package main

import (
	"bufio"
	"encoding/hex"
	"fmt"
	"os"
)

type packet struct {
	version uint64
	typeID  uint64

	literal uint64
	sub     []packet
}

func parsePackets(d []byte) []packet {
	var out []packet

	for len(d) > 8 {
		p, rest := parsePacket(d)
		out = append(out, p)
		d = rest
	}

	return out
}

func parseNumber(d []byte) uint64 {
	var out uint64
	for _, b := range d {
		out <<= 1
		out |= uint64(b)
	}
	return out
}

func parsePacket(d []byte) (packet, []byte) {
	p := packet{}
	p.version, d = parseNumber(d[:3]), d[3:]
	p.typeID, d = parseNumber(d[:3]), d[3:]

	if p.typeID == 4 {
		var bits []byte
		for d[0] == 1 {
			bits, d = append(bits, d[1:5]...), d[5:]
		}
		bits, d = append(bits, d[1:5]...), d[5:]
		p.literal = parseNumber(bits)
	} else {
		if d[0] == 0 {
			var n uint64
			n, d = parseNumber(d[1:16]), d[16:]
			p.sub, d = parsePackets(d[:n]), d[n:]
		} else {
			var n uint64
			n, d = parseNumber(d[1:12]), d[12:]
			for i := uint64(0); i < n; i++ {
				var pp packet
				pp, d = parsePacket(d)
				p.sub = append(p.sub, pp)
			}
		}
	}

	return p, d
}

func evalPacket(p packet) uint64 {
	switch p.typeID {
	case 0:
		sum := uint64(0)
		for _, pp := range p.sub {
			sum += evalPacket(pp)
		}
		return sum

	case 1:
		prod := uint64(1)
		for _, pp := range p.sub {
			prod *= evalPacket(pp)
		}
		return prod

	case 2:
		min := evalPacket(p.sub[0])
		for _, pp := range p.sub[1:] {
			if cur := evalPacket(pp); cur < min {
				min = cur
			}
		}
		return min

	case 3:
		max := evalPacket(p.sub[0])
		for _, pp := range p.sub[1:] {
			if cur := evalPacket(pp); cur > max {
				max = cur
			}
		}
		return max

	case 4:
		return p.literal

	case 5:
		a := evalPacket(p.sub[0])
		b := evalPacket(p.sub[1])
		if a > b {
			return 1
		}
		return 0

	case 6:
		a := evalPacket(p.sub[0])
		b := evalPacket(p.sub[1])
		if a < b {
			return 1
		}
		return 0

	case 7:
		a := evalPacket(p.sub[0])
		b := evalPacket(p.sub[1])
		if a == b {
			return 1
		}
		return 0

	default:
		return 0
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	out, _ := hex.DecodeString(sc.Text())

	bits := make([]byte, len(out)*8)
	for i, b := range out {
		for j := 0; j < 8; j++ {
			bits[i*8+j] = (b >> (8 - 1 - j)) & 1
		}
	}

	ps := parsePackets(bits)
	fmt.Println(evalPacket(ps[0]))
}
