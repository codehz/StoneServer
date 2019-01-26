#pragma once

class MinecraftCommands;
class Level;

class Minecraft {

public:

    MinecraftCommands* getCommands();
    Level *getLevel() const;
    void activateWhitelist();

};