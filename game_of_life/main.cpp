#include <iostream>
#include <tuple>
#include <string>

#include <unistd.h>


const int dim = 10;

int BOARD[dim][dim];

#define WHITE_SQUARE "\u2B1C"
#define RED_SQUARE "\U0001F7E5"



void setup_board() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            BOARD[i][j] = 0;
        }
    }
}

void print_board() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (BOARD[i][j]) {
                std::cout << RED_SQUARE << " " << std::flush;
            } 
            else {
                std::cout << WHITE_SQUARE << " " << std::flush;
            }
            
        }
        std::cout << std::endl;
    }
}

int mod(int a, int b) {
    int r = a % b;
    return (r < 0 ? r + b : r);
}

int neighbor_count(int x, int y) {
    int neighbor_count = 0;



    int neighbors[] = {
        BOARD[mod(x-1, dim)][mod(y-1, dim)], BOARD[mod(x, dim)][mod(y-1, dim)],
        BOARD[mod(x+1, dim)][mod(y-1, dim)], BOARD[mod(x+1, dim)][mod(y, dim)],
        BOARD[mod(x+1, dim)][mod(y+1, dim)], BOARD[mod(x, dim)][mod(y+1, dim)], 
        BOARD[mod(x-1, dim)][mod(y+1, dim)], BOARD[mod(x-1, dim)][mod(y, dim)]
    };

    for (int i = 0; i < 8; i++) {
                
        if(neighbors[i] == 1) {
            neighbor_count++;
        }
    }

    return neighbor_count;

}

void user_entry() {
    std::cout << "Enter the squares that you want to initially populate. If you want to quit, type q" << std::endl << std::endl;
    int i = 1;
    while (true) {
        char user_x, user_y;
        std::cout << i << "x: " << std::flush;
        std::cin >> user_x;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
        if (static_cast<int>(user_x) == 113) { 
            break;
        }
        std::cout << i << "y: " << std::flush;
        std::cin >> user_y;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        if (static_cast<int>(user_y) == 113) { 
            break;
        }
        
        int x = static_cast<int>(user_x) - static_cast<int>('0');
        int y = static_cast<int>(user_y) - static_cast<int>('0');
        
        x = mod(x, dim);
        y = mod(y, dim);

        BOARD[x][y] = 1;
        std::cout << "Added live cell to (" << x << ", " << y << ")" << std::endl << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void pregame_setup() {
    setup_board();
    user_entry();
    std::cout << "This is the starting board: " << std::endl;
    print_board();

}


void add_updates(std::vector<std::tuple<int, int, int>> &updates) {
    
    for (int i = 0; i < dim ; i++) {
        for (int j = 0; j < dim; j++) {
            int nc = neighbor_count(i, j);
            if (BOARD[i][j] == 1) { // alive cell
                if (nc < 2 || nc > 3) {
                    updates.push_back(std::make_tuple(i, j, 0)); // cell dies
                }
            }
            else { // dead cell
                if (nc == 3) {
                    updates.push_back(std::make_tuple(i, j, 1)); // cell resurrects
                }
            }
        }
    }
}


void implement_updates(std::vector<std::tuple<int, int, int>> &updates) {

    for (auto& update : updates) { 
        auto [i, j, state] = update;
        BOARD[i][j] = state;
    }
    updates.clear();

}

void evolve() {

    std::vector<std::tuple<int, int, int>> updates;
    
    // 1) traverse current board and add things to the work queue
    
    add_updates(updates);
    
    
    // 2) loop through the work queue and make those changes O(n)
    
    implement_updates(updates);


}

bool is_extinct() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (BOARD[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {        

    pregame_setup();    


    std::cout << "----------------------------" << std::endl;

    std::cout << "Press enter to start / go to the next iteration" << std::endl;

    int i = 0;


    while (true) {
        usleep(500 * 1000); // 0.5 seconds
        // std::string user_input;
        // std::getline(std::cin, user_input);

        // if(!user_input.empty()) {
        //     break;
        // }

        i++;
        std::cout << "Iteration " << i << ": " << std::endl;

        evolve();
        print_board();
        std::cout << "----------------------------" << std::endl;
        bool extinct = is_extinct();

        if (extinct == true) {
            break;
        }

    }



    return 0;
}



