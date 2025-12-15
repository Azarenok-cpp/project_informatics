#include "logic.h"
#include "util.h"

void stat_words_len(string st)
{
    const string PREP = " \t\n\r.,;:!?()ЧЂї\"'";
    const string END = ".?!";
    map<int, int> w_lengths;
    map<int, int> s_lengths;

    st.append(" ");
    string st_copy = st;

    while (!st.empty() && st.find_first_not_of(PREP) != string::npos) {
        while (!st.empty() && PREP.find(st[0]) != string::npos)
            st.erase(0, 1);
        if (st.empty()) break;

        size_t pos = st.find_first_of(PREP);
        string word;
        if (pos == string::npos) {
            word = st;
            st.clear();
        }
        else {
            word = st.substr(0, pos);
            st.erase(0, pos + 1);
        }

        if (!word.empty())
            w_lengths[static_cast<int>(word.length())] += 1;

        while (!st.empty() && PREP.find(st[0]) != string::npos)
            st.erase(0, 1);
    }

    st = st_copy;

    while (st.find_first_of(END) != string::npos) {
        size_t end_pos = st.find_first_of(END);
        string sent = st.substr(0, end_pos + 1);
        sent.append(" ");

        int words_in_current_sent = 0;

        while (!sent.empty() && sent.find_first_not_of(PREP) != string::npos) {
            while (!sent.empty() && PREP.find(sent[0]) != string::npos)
                sent.erase(0, 1);
            if (sent.empty()) break;

            size_t pos = sent.find_first_of(PREP);
            string word;
            if (pos == string::npos) {
                word = sent;
                sent.clear();
            }
            else {
                word = sent.substr(0, pos);
                // удал€ем слово + разделитель
                sent.erase(0, pos + 1);
            }

            if (!word.empty())
                words_in_current_sent++;

            while (!sent.empty() && PREP.find(sent[0]) != string::npos)
                sent.erase(0, 1);
        }

        if (words_in_current_sent > 0)
            s_lengths[words_in_current_sent] += 1;

        st.erase(0, end_pos + 1);
    }

    int total_words = 0;
    for (const auto& p : w_lengths) total_words += p.second;
    int total_sents = 0;
    for (const auto& p : s_lengths) total_sents += p.second;

    cout << fixed << setprecision(2);
    cout << "--- Words statistic ---" << endl;
    cout << left << setw(25) << "Letters in word" << "Word count" << '\n';
    if (total_words == 0) {
        cout << "No words found." << endl;
    }
    else {
        for (const auto& p : w_lengths) {
            if (p.first == 0) continue;
            cout << left << setw(25) << p.first << p.second
                << " (" << 100.0 * p.second / total_words << "%)" << '\n';
        }
    }

    cout << endl << "--- Sentences statistic ---" << endl;
    cout << left << setw(25) << "Words in sentence" << "Sentence count" << '\n';
    if (total_sents == 0) {
        cout << "No sentences found." << endl;
    }
    else {
        for (const auto& p : s_lengths) {
            cout << left << setw(25) << p.first << p.second
                << " (" << 100.0 * p.second / total_sents << "%)" << '\n';
        }
    }
}
