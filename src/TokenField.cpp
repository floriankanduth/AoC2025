//
// Created by flo on 13.01.26.
//

#include "../inc/TokenField.h"

#include <cassert>
#include <iostream>

namespace day7 {
    TokenField::TokenField(const std::vector<std::string> &input) {
        assert(!input.empty());
        parse_input(input);
        assert(!tokens.empty());
        height = tokens.size();
        width = tokens[0].size();
        beams.insert(find_initial_beam());
    }

    unsigned int TokenField::get_width() const {
        return width;
    }

    unsigned int TokenField::get_height() const {
        return height;
    }

    Token TokenField::get_token(const unsigned int line, const unsigned int pos) const {
        assert(line < get_width());
        assert(pos < get_height());
        return tokens[pos][line];
    }

    void TokenField::set_token(const unsigned int line, const unsigned int pos, const Token token) {
        assert(line < get_width());
        assert(pos < get_height());

        tokens[pos][line] = token;
    }

    void TokenField::print() const {
        for (const auto &line: tokens) {
            for (const Token &c: line) {
                std::cout << static_cast<char>(c);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    unsigned int TokenField::find_initial_beam() const {
        for (int x = 0; x < width; ++x) {
            if (tokens[0][x] == BeamOrigin) {
                return x;
            }
        }
        assert(false && "No Beam Origin found in line");
    }

    Token TokenField::char_to_token(const char c) {
        switch (c) {
            case BeamOrigin:
                return BeamOrigin;
            case Splitter:
                return Splitter;
            case Beam:
                return Beam;
            case Empty:
                return Empty;
            default:
                assert(false && "Unknown token");
        }
        return Error;
    }

    void TokenField::parse_input(const std::vector<std::string> &input) {
        for (const auto &line: input) {
            std::vector<Token> field_line;
            for (const char &c: line) {
                field_line.push_back(char_to_token(c));
            }
            tokens.push_back(field_line);
        }
    }

    void TokenField::insert_beam(const unsigned int beam, const unsigned int line) {
        assert(beam < get_width());
        assert(line < get_height());

        beams.insert(beam);
        set_token(beam, line, Beam);
    }

    void TokenField::destroy_beam(const unsigned int beam) {
        assert(beam < get_width());

        beams.erase(beam);
    }

} // day7
