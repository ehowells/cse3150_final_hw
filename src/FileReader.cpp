// ===========================================================
// FileReader: loads a deck from a CSV
// Format: Suit,Rank or Joker,Color
// ===========================================================
#include <string>
#include <istream>
#include <fstream>
#include <stdexcept>

class FileReader {
public:
    static Deck readDeckFromCSV(const std::string& path) {
        Deck deck;
        std::ifstream file(path);
        if (!file.is_open())
            throw std::runtime_error("Failed to open input deck: " + path);

        try {
            std::string line;
            while (std::getline(file, line)) {
                if (line.empty()) continue;

                size_t commaPos = line.find(',');
                if (commaPos == std::string::npos)
                    throw std::runtime_error("Malformed CSV input");
            
                std::string suit = line.substr(0, commaPos);
                std::string value = line.substr(commaPos + 1);
                
                if (suit.empty() || value.empty())
                    throw std::runtime_error("Malformed CSV input");
                
                if (suit == "Joker") {
                    deck.addCard(std::make_unique<JokerCard>(value));
                } else {
                    int rank = std::stoi(value);
                    if (rank < 1 || rank > 13)
                        throw std::runtime_error("Malformed CSV input");

                    if (rank >= 11)
                        deck.addCard(std::make_unique<FaceCard>(suit, rank));
                    else
                        deck.addCard(std::make_unique<PlayingCard>(suit, rank));
                }
            }
        } catch (...) {
            throw std::runtime_error("Malformed CSV input");
        }

        if(deck.sizer() == 0)
            throw std::runtime_error("Empty of invalid CSV deck");

        return deck;
    }
};