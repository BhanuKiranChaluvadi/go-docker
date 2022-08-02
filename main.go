package main

import (
	"bufio"
	"context"
	"fmt"
	"log"

	"github.com/docker/docker/api/types"
	"github.com/docker/docker/client"
	"github.com/docker/docker/pkg/archive"
)

func main() {
	tar, err := archive.TarWithOptions("example/daemon-cpp", &archive.TarOptions{})
	if err != nil {
		log.Printf("archive.TarWithOptions is %v", err)
	}

	opts := types.ImageBuildOptions{
		Dockerfile: "Dockerfile",
		Tags:       []string{"qperixdkajciospo" + "rocketmq_test"},
		Remove:     true,
	}

	// Create docker client
	ctx := context.Background()
	docker, err := client.NewClientWithOpts(client.FromEnv, client.WithAPIVersionNegotiation())
	if err != nil {
		log.Printf("ImageBuild: NewClient(): %v", err)
	}

	res, err := docker.ImageBuild(ctx, tar, opts)
	if err != nil {
		log.Printf("Imagebuild is %v", err)
	}
	log.Printf("res.Body is = %v", res.Body)

	defer res.Body.Close()
	scanner := bufio.NewScanner(res.Body)
	for scanner.Scan() {
		lastLine := scanner.Text()
		fmt.Println(lastLine)
	}
}
