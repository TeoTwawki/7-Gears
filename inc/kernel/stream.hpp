#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <SDL_types.h>

class Stream
{
public:
    explicit Stream(const std::string& fileName);
    explicit Stream(std::vector<Uint8>&& data);
    void ReadUInt8(Uint8& output);
    void ReadUInt32(Uint32& output);
    void ReadUInt16(Uint16& output);
    void ReadSInt16(Sint16& output);
    void ReadBytes(Sint8* pDest, size_t destSize);
    void ReadBytes(Uint8* pDest, size_t destSize);
    void Seek(size_t pos);
    size_t Pos() const;
    size_t Size() const;
    bool AtEnd() const;
    std::string Name() const { return mName; }
private:
    mutable std::unique_ptr<std::istream> mStream;
    size_t mSize = 0;
    std::string mName;
};

