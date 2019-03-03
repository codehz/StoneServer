workflow "Build" {
  on = "push"
  resolves = ["appleboy/telegram-action@master"]
}

action "login" {
  uses = "actions/docker/login@c08a5fc9e0286844156fefff2c141072048141f6"
  secrets = ["DOCKER_PASSWORD", "DOCKER_USERNAME"]
}

action "build" {
  uses = "codehz/StoneActions/build@master"
}

action "package" {
  uses = "codehz/StoneActions/package@master"
  needs = ["build"]
}

action "push" {
  uses = "actions/docker/cli@c08a5fc9e0286844156fefff2c141072048141f6"
  needs = ["package", "login"]
  args = "push codehz/stoneserver:latest"
}

action "appleboy/telegram-action@master" {
  uses = "appleboy/telegram-action@master"
  needs = ["push"]
  secrets = [
    "TELEGRAM_TOKEN",
    "TELEGRAM_TO",
  ]
}
