# StoneServer

> Warning: Working in progress. Doesn't work.

A modded minecraft bedrock edition server

Modified from MrARM's mcpelauncher-server for cloud-native

## Difference from MrARM's mcpelauncher-server
Removed features: 
1. Read command from stdin
2. Custom arguments

Added features:
1. D-Bus interface for command and remote control
2. Designed for container

## DBus Interface

### Interface: *one.codehz.stone.CoreService.\<SUFFIX>*
#### Method: *stop* () ↦ ()
Stop the server.
#### Signal: *log* (Int32 *level*, String *tag*, String *content*)
Server log signal.
### Interface: *one.codehz.stone.CommandService.\<SUFFIX>*
#### Method: *complete* (String *command*, UInt32 *position*) ↦ (Array of [Struct of (String *name*, String *title*, String *description*, Int32 *offset*, Int32 *eat*, Int32 *item_id*)] *options*)
Get the list of the auto-complete options.
#### Method: *execute* (String *origin_name*, String *command*) ↦ (String *result*)
Execute a command and collect the output.

> PS: The **Bus Name** is same as the **Interface Name**
>
> Example:
> 1. Stop the server:
>    * `dbus-send --type=method_call --print-reply --session --dest=one.codehz.stone.CoreService.default /one/codehz/stone/CoreService/default one.codehz.stone.CoreService.stop`
>    * `busctl call --user one.codehz.stone.CoreService.default /one/codehz/stone/CoreService/default one.codehz.stone.CoreService stop`
> 2. Execute the command:
>    * `dbus-send --type=method_call --print-reply --session --dest=one.codehz.stone.CommandService.default /one/codehz/stone/CommandService/default one.codehz.stone.CommandService.default.execute string:server string:/help`
>    * `busctl call --user one.codehz.stone.CommandService.default /one/codehz/stone/CommandService/default one.codehz.stone.CommandService.default execute ss server /help`

# COPYRIGHT

Copyright © 2018 CodeHz

Released under the AGPL 3.0
[LICENSE](./LICENSE)