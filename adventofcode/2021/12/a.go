package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

type node struct {
	name  string
	conns []*node
}

func main() {
	g := make(map[string]*node)

	sc := bufio.NewScanner(os.Stdin)
	for sc.Scan() {
		parts := strings.Split(sc.Text(), "-")
		if len(parts) != 2 {
			continue
		}

		g1, ok := g[parts[0]]
		if !ok {
			g1 = &node{name: parts[0]}
			g[parts[0]] = g1
		}
		g2, ok := g[parts[1]]
		if !ok {
			g2 = &node{name: parts[1]}
			g[parts[1]] = g2
		}

		g1.conns = append(g1.conns, g2)
		g2.conns = append(g2.conns, g1)
	}

	ans := dfs(g["start"], make(map[*node]bool, len(g)))
	fmt.Println(ans)
}

func dfs(n *node, seen map[*node]bool) int {
	if n.name == "end" {
		return 1
	}

	if !unicode.IsUpper(rune(n.name[0])) {
		if seen[n] {
			return 0
		}
		seen[n] = true
		defer delete(seen, n)
	}

	cnt := 0
	for _, g := range n.conns {
		cnt += dfs(g, seen)
	}

	return cnt
}
