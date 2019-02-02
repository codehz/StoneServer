workflow "Build test" {
  on = "push"
  resolves = ["build"]
}

action "build" {
  uses = "codehz/StoneActions/build@de5d8fda0706e5cd1504ad635e95c7b80e9e0494"
}
