package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	//lint:ignore ST1001 pc
	. "image"
)

type board struct {
	grid  [5][5]int
	marks [5][5]bool
	ind   map[int]Point
	win   bool
}

func (b *board) index() {
	b.ind = make(map[int]Point, 25)
	for i := range b.grid {
		for j := range b.grid[i] {
			b.ind[b.grid[i][j]] = Pt(i, j)
		}
	}
}

func (b *board) mark(n int) (bool, int) {
	if b.win {
		return false, 0
	}

	p, ok := b.ind[n]
	if !ok {
		return false, 0
	}
	b.marks[p.X][p.Y] = true

	winx, winy := true, true
	for i := 0; i < 5; i++ {
		winx = b.marks[i][p.Y] && winx
	}
	for i := 0; i < 5; i++ {
		winy = b.marks[p.X][i] && winy
	}

	if !winx && !winy {
		return false, 0
	}
	b.win = true

	score := 0
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			if !b.marks[i][j] {
				score += b.grid[i][j]
			}
		}
	}

	return true, score
}

func main() {
	sc := bufio.NewScanner(os.Stdin)

	sc.Scan()
	var nums []int
	for _, s := range strings.Split(sc.Text(), ",") {
		n, _ := strconv.Atoi(s)
		nums = append(nums, n)
	}

	var boards []*board
	for sc.Scan() {
		b := &board{}
		for i := 0; i < 5; i++ {
			sc.Scan()
			for j, s := range strings.Fields(sc.Text()) {
				n, _ := strconv.Atoi(s)
				b.grid[i][j] = n
			}
		}
		b.index()

		boards = append(boards, b)
	}

	var wins []int
	for _, n := range nums {
		for _, b := range boards {
			win, score := b.mark(n)
			if win {
				wins = append(wins, score*n)
			}
		}
	}

	fmt.Println(wins[len(wins)-1])
}
