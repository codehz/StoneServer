workflow "Build test" {
  on = "push"
  resolves = ["build"]
}

action "build" {
  uses = "codehz/StoneActions/build"
}
