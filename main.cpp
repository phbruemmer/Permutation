#include <iostream>
#include <array>

namespace combinatorics {

    using namespace std;

    class Permutation
    {
    public:
        void init_fn();
        void permute();
        void input_fn();
        void print_array();
        void swap_position(int pos1, int pos2);
        void permutation_fn(int position);

    private:
        int x_size = 0;
        array<int, 8> nums{};
    };

    void Permutation::init_fn() {
        for (int i = 0; i < x_size; i++)
        {
            nums[i] = i + 1;
        }
    }

    void Permutation::permute() {
        permutation_fn(x_size);
    }

    void Permutation::input_fn()
    {
        cout << "[Eingabe] Bitte groesse eingeben (zwischen 1 und 8): " << endl;
        int v_size;
        do
        {
            cin >> v_size;
        } while (v_size < 1 || v_size > 9);
        x_size = v_size;
    }

    void Permutation::print_array()
    {
        for (int i = 0; i < x_size; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    void Permutation::swap_position(int pos1, int pos2)
    {
        if (pos2 < nums.size() && pos1 < nums.size())
        {
            int temp = nums[pos1];
            nums[pos1] = nums[pos2];
            nums[pos2] = temp;
        }
    }

    /*

      print_array(); // Ausgabe vom Array
        if (max_iterations == 1) { // Base Case -> Beendet rekursive Funktion
            return;
        } else {
            // cout << position << endl;
            swap_position(position); // Tausche position und position + 1
            if (position == 0) { position = max_position;} else { position--; } // Wenn Position 0, setze Position gleich max_position, wenn nicht, dekrementiere position.
            permutation_fn(max_iterations - 1, position); // Rekursiver Aufruf von permutation_fn()
        }

     * */

    void Permutation::permutation_fn(int position)
    {
        // Base Case
        if (position == 1) {
            print_array();
            return;
        }

        permutation_fn(position - 1);

        for (int i = 0; i < position - 1; i++) {
            if (position % 2 == 0) {
                swap_position(i, position - 1);
            } else {
                swap_position(0, position - 1);
            }
            permutation_fn(position - 1);
        }
    }
}

// https://de.wikipedia.org/wiki/Heap-Algorithmus


int main()
{
    combinatorics::Permutation permutation{};
    permutation.input_fn();
    permutation.init_fn();
    permutation.permute();

    return 0;
}
