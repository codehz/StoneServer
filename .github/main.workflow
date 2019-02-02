workflow "Build test" {
  on = "push"
  resolves = ["build"]
}

action "build" {
  uses = "codehz/StoneActions/build@df793763bd26ade6b27836abbe4089e584afe926"
}
