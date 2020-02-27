#include "StateGame.h"

namespace CME {
    StateGame::StateGame()
    {
        test_data = "NOTHING";
    }

    StateGame::~StateGame()
    {
        //dtor
    }

    int StateGame::init()
    {

        // text
        std::ifstream in_file;
        in_file.open("resources\\testdata.txt");
        if(!in_file)
        {
            return I_ASSET_LOAD_ERROR;
        }
        std::string line_in;
        while(in_file >> line_in)
        {
            test_data += line_in;
        }
        in_file.close();

        // font
        if(!font.loadFromFile("resources\\arial.ttf"))
        {
            return I_ASSET_LOAD_ERROR;
        }
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);

        // counter
        test_counter = 0;

        return 0;
    }

    void StateGame::clean()
    {
        std::ofstream out_stream;
        out_stream.open("resources\\userdata.txt");
        out_stream << test_counter << " player data saved!\n" << std::endl;
        out_stream.close();
    }

    void StateGame::update(sf::RenderWindow& window, const float time_delta)
    {
        test_counter++;
    }

    void StateGame::draw(sf::RenderTarget& target, const float interp)
    {
        std::string out = test_data + "  " + std::to_string(test_counter);
        text.setString(out);
        target.draw(text);
    }
}
