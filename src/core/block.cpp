#include "block.h"

Block::Block() : metatileId(0), collision(0), elevation(0) { }

Block::Block(uint16_t metatileId, uint16_t collision, uint16_t elevation) :
    metatileId(metatileId),
    collision(collision),
    elevation(elevation)
{  }

Block::Block(uint16_t word) :
    metatileId(word & 0x1FFF),
    collision(0),
    elevation((word >> 13) & 0x7)
{  }

Block::Block(const Block &other) :
    metatileId(other.metatileId),
    collision(other.collision),
    elevation(other.elevation)
{  }

Block &Block::operator=(const Block &other) {
    metatileId = other.metatileId;
    collision = other.collision;
    elevation = other.elevation;
    return *this;
}

uint16_t Block::rawValue() const {
    return static_cast<uint16_t>(
                (metatileId & 0x1FFF) +
                ((elevation & 0x7) << 13));
}

bool Block::operator ==(Block other) const {
    return (metatileId == other.metatileId) && (collision == other.collision) && (elevation == other.elevation);
}

bool Block::operator !=(Block other) const {
    return !(operator ==(other));
}
