#include <iostream>


struct ChessPosition
{
    
    ChessPosition(unsigned short row = 0, char col = 'Z') {
        this->rows = row;
        this->cols = col;
    }
    unsigned short int rows;
    char cols;
    bool operator==(const ChessPosition& other) const
    {
        return this->rows == other.rows && this->cols == other.cols;
    }
    bool operator!=(const ChessPosition& other) const
    {
        return !(*this == other);
    }

};

std::ostream& operator<<(std::ostream& out, const ChessPosition& other) {
    out << other.cols << " " << other.rows << " ";
    return out;
}

class ChessPositionVector
{
    std::size_t size;
    std::size_t capacity;
    ChessPosition* positions;

    void resize()
    {
        throw "Method not implemented.";
    }

public:
    ChessPositionVector(const std::size_t cap = 64)
        : size(0), capacity(cap)
    {
        this->positions = new ChessPosition[this->capacity];
    }

    ~ChessPositionVector()
    {
        delete[] this->positions;
    }

    bool contains(const ChessPosition& position) const
    {
        for (std::size_t i = 0; i < this->size; ++i)
        {
            if (this->positions[i] == position) {
                return true;
            }
        }
        return false;
    }
    
    void add(const ChessPosition& position )
    {
        if (size == capacity)
        {
            resize();

        }
        
        this->positions[size] = position;
        size++;
    }
    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << this->positions[i] << " ";
        }
    }
};

class ChessPiece
{
private:
    ChessPosition position;

public:
    ChessPiece(ChessPosition position) : position(position) {}

    ChessPosition getPosition() const
    {
        return position;
    }

    virtual ChessPositionVector allowedMoves() const = 0;

    bool wins(const ChessPosition& position) const
    {
        return this->allowedMoves().contains(position);
    }
};
class Rook : public ChessPiece {
public:
    Rook(ChessPosition position) : ChessPiece(position){}
    ChessPositionVector allowedMoves() const override
    {
        ChessPositionVector result;

        for (char col = 'A'; col <= 'H'; col++)
        {
            ChessPosition currentPosition;
            currentPosition.cols = col;
            currentPosition.rows = getPosition().rows;
            if (currentPosition != getPosition())
            {
                result.add(currentPosition);
            }
        }
        for (unsigned short int row = 1; row <= 8; row++)
        {
            ChessPosition currentPosition;
            currentPosition.rows = row;
            currentPosition.cols = getPosition().cols;
            if (currentPosition != getPosition())
            {
                result.add(currentPosition);
            }
        }

        return result;
    }
};
int main()
{
    Rook whiteRook(ChessPosition(1, 'A'));
    whiteRook.allowedMoves().print();
}

