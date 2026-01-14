//
// Created by flo on 13.01.26.
//

#ifndef AOC_TOKENFIELD_H
#define AOC_TOKENFIELD_H
#include <set>
#include <string>
#include <vector>

namespace day7 {
    enum Token {
        Beam = '|',
        BeamOrigin = 'S',
        Empty = '.',
        Splitter = '^',
        Error = -1,
    };

    class TokenField {
    private:
        unsigned int width, height;
        std::vector<std::vector<Token> > tokens;

        /**
         * Scan the first line of Tokens for BeamOrigin.
         * @return index of BeamOrigin
         */
        unsigned int find_initial_beam() const;

        /**
         * Takes a char and converts it to a Token Enum.
         * This avoids direct casting, which can lead to undefined behavior.
         *
         * @param c Char to convert
         * @return Token with value of Char
         */
        static Token char_to_token(char c);

        /**
         * Set tokens from puzzle input
         * @param input puzzle input as string vector
         */
        void parse_input(const std::vector<std::string> &input);

        void set_token(unsigned int line, unsigned int pos, Token token);

    public:
        /**
         * Set of indices of active beams for faster lookup
         */
        std::set<unsigned int> beams;

        explicit TokenField(const std::vector<std::string> &input);

        unsigned int get_width() const;

        unsigned int get_height() const;

        Token get_token(unsigned int line, unsigned int pos) const;

        /**
         * Print current field
         */
        void print() const;

        /**
         * Add new beam.
         *
         * @param beam index to add
         * @param line where beam is spawned
         */
        void insert_beam(unsigned int beam, unsigned int line);

        /**
         * Destroy beam at index
         * @param beam to destroy
         */
        void destroy_beam(unsigned int beam);

        void split_beam(unsigned int beam);
    };
} // day7

#endif //AOC_TOKENFIELD_H
