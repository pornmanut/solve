package main

import (
	"fmt"
	"os"
	"strconv"
)

//Node is struct that strore key or index,value that contain leaf all of tree
//and left right to next node
type Node struct {
	key   int
	value int
	left  *Node
	right *Node
}

//Tree is struct that contain node to define
type Tree struct {
	root *Node
}

//createTree() return struct tree with root:nil
func createTree() *Tree {
	return &Tree{root: nil}
}

//createNewNode() received arugment key and return with struct node with key and value set to zero
func createNewNode(key int) *Node {
	return &Node{key: key, value: 1, left: nil, right: nil}
}

// Tree.Insert() received arugment key and return tree with insert using Node.insert()
func (t *Tree) insert(key int) *Tree {
	if t.root == nil {
		t.root = createNewNode(key)
	} else {
		t.root.insert(key)
	}
	return t
}
func (t *Tree) inorder() {
	if t.root == nil {
		return
	}
	inorder(t.root)
	fmt.Printf("\n")
}
func (t *Tree) countMoreThan(key int) int {
	return countMoreThan(key, t.root)
}
func inorder(n *Node) {
	if n == nil {
		return
	}
	inorder(n.left)
	fmt.Printf("%d,", n.key)
	// fmt.Printf("(%d,%d),", n.key, n.value)
	inorder(n.right)

}
func countMoreThan(key int, n *Node) int {
	if n == nil {
		return 0
	} else if key == n.key {
		if n.right == nil {
			return 0
		}
		return n.right.value
	} else if key < n.key {
		if n.right == nil {
			return 1 + countMoreThan(key, n.left)
		}
		return 1 + n.right.value + countMoreThan(key, n.left)

	}
	return countMoreThan(key, n.right)

}
func (n *Node) insert(key int) {
	if n == nil {
		return
	} else if key <= n.key {
		n.value++
		if n.left == nil {
			n.left = createNewNode(key)
		} else {
			n.left.insert(key)
		}
	} else {
		n.value++
		if n.right == nil {
			n.right = createNewNode(key)
		} else {
			n.right.insert(key)
		}
	}
}
func main() {

	tree := createTree()
	argv := os.Args
	argc := len(argv)
	if argc >= 3 {
		for i := 2; i < argc; i++ {
			num, err := strconv.Atoi(argv[i])
			if err == nil {
				tree.insert(num)
			} else {
				fmt.Println("only receive interger in set of number")
				break
			}
		}
		tree.inorder()

		target, err := strconv.Atoi(argv[1])
		if err == nil {
			value := tree.countMoreThan(target)
			fmt.Printf("x > %d: total is %d\n", target, value)
		} else {
			fmt.Println("only receive interger in target")

		}

	} else {
		fmt.Println("request more than 2 arugment with {value} {set of number}")
	}
}
