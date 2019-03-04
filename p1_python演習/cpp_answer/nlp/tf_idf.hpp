#include<string>
#include<vector>
#include<set>
#include<fstream>
#include<cmath>

double tf(const std::string& term, const std::vector<std::string>& doc) {
    int num = 0;
    for (const auto& w : doc) {
        if (w == term) {
            num++;
        }
    }
    return (double)num / doc.size();
}

double idf(const std::string& term, const std::vector<std::vector<std::string>>& docs) {
    int df = 0;
    for (const auto& doc : docs) {
        for (const auto& w : doc) {
            if (w == term) {
                df++;
                break;
            }
        }
    }
    return std::log10((double)docs.size() / df) + 1;
}

std::vector<std::vector<double>> tf_idf(const std::vector<std::string>& terms, const std::vector<std::vector<std::string>>& docs) {
    std::vector<std::vector<double>> result(docs.size(), std::vector<double>(terms.size()));
    for (int i = 0; i < docs.size(); i++) {
        for (int j = 0; j < terms.size(); j++) {
            result[i][j] = tf(terms[j], docs[i]) * idf(terms[j], docs);
        }
    }

    return result;
}
