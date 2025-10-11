// ===========================================================
// FileWriter: writes each round to a CSV file
// ===========================================================
#include <string>
#include <fstream>

class FileWriter {
    std::ofstream file_;
public:
    explicit FileWriter(const std::string& path) {
        file_.open(path, std::ios::out | std::ios::trunc);
        if (!file_.is_open())
            throw std::runtime_error("Failed to open output CSV: " + path);
        file_ << "Round,PlayerA_Count,PlayerB_Count,PlayerA_Cards,PlayerB_Cards\n";
    }

    void writeRound(int round, const Deck& a, const Deck& b) {
        file_ << round << "," << a.size() << "," << b.size() << ",\"" << a << "\",\"" << b << "\"\n";
    }
};