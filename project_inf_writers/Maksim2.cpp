#include "logic.h"
#include "util.h"

void stat_chered(string st)
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    map <string, int> stats;
    stats["gl_gl"] = 0;
    stats["gl_sg"] = 0;
    stats["sg_gl"] = 0;
    stats["sg_sg"] = 0;

    int total_after_gl = 0;
    int total_after_sg = 0;

    int prev_type = 0;

    for (int i = 0; i < st.length(); i++) {
        int cur_type = get_char_type(st[i]);

        if (cur_type != 0) {
            if (prev_type == 1) { // если прошла€ была гласна€
                total_after_gl++;
                if (cur_type == 1) stats["gl_gl"]++;
                else               stats["gl_sg"]++;
            }
            else if (prev_type == 2) { // ≈сли прошла€ была согласна€
                total_after_sg++;
                if (cur_type == 1) stats["sg_gl"]++;
                else               stats["sg_sg"]++;
            }
            prev_type = cur_type;
        }
        else {
            prev_type = 0;
        }
    }

    cout << "\n--- Alternation stats ---" << endl;
    cout << fixed << setprecision(2);

    cout << "If the letter is a vowel, it is followed by:" << endl;
    if (total_after_gl > 0) {
        double proc_gl = double(stats["gl_gl"]) * 100 / total_after_gl;
        double proc_sg = double(stats["gl_sg"]) * 100 / total_after_gl;
        cout << "   - Vowel:     " << stats["gl_gl"] << " times (" << proc_gl << "%)" << endl;
        cout << "   - Consonant: " << stats["gl_sg"] << " times (" << proc_sg << "%)" << endl;
    }

    cout << endl;

    cout << "If the letter is a consonant, it is followed by:" << endl;
    if (total_after_sg > 0) {
        double proc_gl = double(stats["sg_gl"]) * 100 / total_after_sg;
        double proc_sg = double(stats["sg_sg"]) * 100 / total_after_sg;
        cout << "   - Vowel:     " << stats["sg_gl"] << " times (" << proc_gl << "%)" << endl;
        cout << "   - Consonant: " << stats["sg_sg"] << " times (" << proc_sg << "%)" << endl;
    }

}
