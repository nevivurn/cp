package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)

	sc.Scan()
	templ := sc.Text()
	sc.Scan() // skip empty line

	rules := make(map[string]string)
	for sc.Scan() {
		if sc.Text() == "" {
			continue
		}
		fs := strings.Fields(sc.Text())
		rules[fs[0]] = fs[2]
	}

	pairs := make(map[string]int)
	double := make(map[string]int)
	for i := range templ[:len(templ)-1] {
		pairs[templ[i:i+2]]++
		if i != 0 {
			double[templ[i:i+1]]++
		}
	}

	for i := 0; i < 10; i++ {
		next := make(map[string]int)
		for k, v := range pairs {
			c, ok := rules[k]
			if !ok {
				next[k] += v
				continue
			}

			next[k[:1]+c] += v
			next[c+k[1:]] += v
			double[c] += v
		}
		pairs = next
	}

	totals := make(map[string]int)
	for k, v := range pairs {
		totals[k[:1]] += v
		totals[k[1:]] += v
	}

	ints := make([]int, 0, len(totals))
	for k, v := range totals {
		ints = append(ints, v-double[k])
	}
	sort.Ints(ints)
	fmt.Println(ints[len(ints)-1] - ints[0])
}
