workflow "Build test" {
  on = "push"
  resolves = ["build"]
}

action "build" {
  uses = "codehz/StoneActions/build@7b4fdc8c601dd264c0dfd9c7b8126c62bfd6e6be"
}
