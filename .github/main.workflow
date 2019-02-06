workflow "Build" {
  on = "push"
  resolves = ["push"]
}

action "login" {
  uses = "actions/docker/login@c08a5fc9e0286844156fefff2c141072048141f6"
  secrets = ["DOCKER_PASSWORD", "DOCKER_USERNAME"]
}

action "build" {
  uses = "codehz/StoneActions/build@7e12c8c0bdde6f4d52ab74d8348de46f38e48ae7"
}

action "package" {
  uses = "codehz/StoneActions/package@7e12c8c0bdde6f4d52ab74d8348de46f38e48ae7"
  needs = ["build"]
}

action "push" {
  uses = "actions/docker/cli@c08a5fc9e0286844156fefff2c141072048141f6"
  needs = ["package", "login"]
  args = "push codehz/stoneserver:latest"
}
