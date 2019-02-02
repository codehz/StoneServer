workflow "Build test" {
  on = "push"
  resolves = ["push"]
}

action "login" {
  uses = "actions/docker/login@c08a5fc9e0286844156fefff2c141072048141f6"
  secrets = ["DOCKER_PASSWORD", "DOCKER_USERNAME"]
}

action "build" {
  uses = "codehz/StoneActions/build@f714a4f1428e6a736861a036bfe75c01cbe2914f"
}

action "package" {
  uses = "codehz/StoneActions/package@f714a4f1428e6a736861a036bfe75c01cbe2914f"
  needs = ["build"]
}

action "push" {
  uses = "actions/docker/cli@c08a5fc9e0286844156fefff2c141072048141f6"
  needs = ["package", "login"]
  args = "push codehz/stoneserver:latest"
}
