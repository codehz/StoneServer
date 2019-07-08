# StoneServer

A modded minecraft bedrock edition server

Modified from MrARM's mcpelauncher-server for cloud-native

## Difference from MrARM's mcpelauncher-server
Removed features:
1. Read command from stdin
2. Custom arguments

Added features:
1. WebSocket JSON-RPC 2.0 API Interface
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
server-ip=0.0.0.0
server-ip-v6=::
```

PS1: You must turn on the experiment-mode to use the scripting feature

PS2: Turn on the cheats option to enable command in game

## Installation & Deployment

### Recommanded: using stonectl

1. Download prebuilt binary https://github.com/codehz/stonectl/releases/latest
2. `chmod +x ./stonectl`
3. `./stonectl install`
4. Create a empty directory for data (eg. 'MinecraftData)
5. `./stonectl start MinecraftData`

PS: You can have multiple service instance(by create different directories)

#### Execute command (with realtime log)

`./stonectl attach MinecraftData`

#### Shutdown the server

`./stonectl stop MinecraftData`

### Using docker

image: codehz/stoneserver

```bash
docker run -p 19132:19132/udp -v game:/run/game -v data:/run/data codehz/stoneserver
```

PS: You need a minecraft copy from MrARM's mcpelauncher

### Build from source

#### Dependencies

* cmake
* make
* glibc (i386)
* readline (i386)
* python3
* gcc/g++ (8.3.0+)

#### Steps

```
git clone https://github.com/codehz/StoneServer
cd StoneServer
mkdir -p build
cd build
cmake ..
make
sudo make install
```

And now you can run `stone` directly

## Other resources

(for external program, not for the scripting engine) JS API: [stoneapi-js](https://www.npmjs.com/package/stoneapi-js)

# COPYRIGHT

Copyright © 2019 CodeHz

Released under the AGPL 3.0
[LICENSE](./LICENSE)