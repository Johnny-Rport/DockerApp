# Run DockerApp Script
# This enables xhost then runs appropiate docker file using compose then shuts it down

xhost +local:docker
sudo docker compose -f /home/jar/Projects/DockerApp/compose.yaml up
xhost -local:docker

