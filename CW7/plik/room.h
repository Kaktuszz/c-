#ifndef ROOM_H
#define ROOM_H

class Room{

    private:
        std::string wall_color;
        float width;
        float breadth;
        float height;

    public:
        Room(); // domyślny konstruktor
        Room(float w, float b, float h, std::string col); // konstruktor
        ~Room(); // destruktor

        float CalcAera();
        float CalcVolume();

};

#endif