# StoneServer

> Warning: Working in progress. Doesn't work.

A modded minecraft bedrock edition server

Modified from MrARM's mcpelauncher-server for cloud-native

## Difference from MrARM's mcpelauncher-server
Removed features: 
1. Read command from stdin
2. Custom arguments

Added features:
1. APID Interface
2. Designed for container runtime (docker or my nsroot)
3. Scripting Feature! (with some custom scripting api)

## Template for server.properities

```
activate-whitelist=false
player-idle-timeout=0.000000
gamemode=0
tick-distance=4
level-seed=<random>
edu-mode=false
motd=A Minecraft Server
online-mode=false
level-generator=1
level-dir=world
level-name=world
experiment-mode=false
max-players=20
texturepack-required=false
server-port-v6=19133
force-gamemode=false
view-distance=10
difficulty=0
cheats-enabled=false
server-port=19132
```

PS1: You must change the experiment-mode to true to enable the scripting feature
PS2: Turn on the cheats option to enable command in game

## Other resources

(for external program, not for the scripting engine) JS API: [stoneapi-js](https://www.npmjs.com/package/stoneapi-js)

# COPYRIGHT

Copyright © 2018 CodeHz

Released under the AGPL 3.0
[LICENSE](./LICENSE)