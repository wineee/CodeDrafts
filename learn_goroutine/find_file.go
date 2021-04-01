package main

import (
	"fmt"
	"io/ioutil"
	"time"
)

var query = "test"
var matches int

//
var workerCount = 0
var maxWorkerCount = 32
var searchRequest = make(chan string)
var workerDone = make(chan bool)
var foundMatch = make(chan bool)
//

func main() {
	start := time.Now()
	workerCount = 1
	go search("/home/rew/", true)
	waitForWorkers()
	fmt.Println(matches, "matcher")
	fmt.Println(time.Since(start))
}

func waitForWorkers() {
	for {
		select {
		case path := <- searchRequest:
			workerCount++
			go search(path, true)
		case <- workerDone:
			workerCount--
			if workerCount == 0 {
				return
			}
		case <- foundMatch:
			matches++
		}
	}
}

func search(path string, master bool) {
	files, err := ioutil.ReadDir(path)
	if err == nil {
		for _, file := range files {
			name := file.Name()
			if name == query {
				//matches++
				foundMatch <- true
			}
			if file.IsDir() {
				if workerCount < maxWorkerCount {
					searchRequest <- path + name + "/"
				} else {
					search(path + name + "/", false)
				}
			}
		}
	}

	if master {
		workerDone <- true
	}
}
