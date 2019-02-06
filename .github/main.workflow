workflow "Build test" {
  on = "push"
  resolves = ["push"]
}

action "login" {
  uses = "actions/docker/login@c08a5fc9e0286844156fefff2c141072048141f6"
  secrets = ["DOCKER_PASSWORD", "DOCKER_USERNAME"]
}

action "build" {
  uses = "codehz/StoneActions/build@979f73d5baed36f3f8abca1c4ab197b319707589"
}

action "package" {
  uses = "codehz/StoneActions/package@979f73d5baed36f3f8abca1c4ab197b319707589"
  needs = ["build"]
}

action "push" {
  uses = "actions/docker/cli@c08a5fc9e0286844156fefff2c141072048141f6"
  needs = ["package", "login"]
  args = "push codehz/stoneserver:latest"
}
