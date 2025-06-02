#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Movie {
    string title;
    double rating;
};

// TODO: MovieProcessor �߻� Ŭ���� ����
// ���� ���� �Լ� process�� �����ؾ� �մϴ�.
// process�� vector<Movie>&�� ���ڷ� �޾ƾ� �մϴ�.
class MovieProcessor {
public:
    virtual void process(vector<Movie>& movies) = 0;
    virtual ~MovieProcessor() {}
};

// �⺻ ��ȭ ������
class MovieManager {
private:
    vector<Movie> movies;
    map<string, double> movieMap;

public:
    MovieManager() {
        // �ʱ� ������ ����
        movies = {
            {"Inception", 9.0},
            {"Interstellar", 8.6},
            {"The Dark Knight", 9.1},
            {"Memento", 8.4}
        };

        for (const auto& movie : movies) {
            movieMap[movie.title] = movie.rating;
        }
    }

    void printMovies() {
        cout << "��ȭ ���:\n";
        for (const auto& movie : movies) {
            cout << "����: " << movie.title << ", ����: " << movie.rating << "\n";
        }
    }

    void findMovie(const string& title) {
        auto it = movieMap.find(title);
        if (it != movieMap.end()) {
            cout << "��ȭ ����: " << it->first << ", ����: " << it->second << "\n";
        }
        else {
            cout << "�ش� ��ȭ�� ��Ͽ� �����ϴ�.\n";
        }
    }

    // MovieProcessor�� ����Ͽ� ��� Ȯ��
    void processMovies(MovieProcessor& processor) {
        processor.process(movies);
    }

};


// TODO: compareMovies �Լ� ����
// Movies ��ü�� ��Ҹ� ���ϴ� �Լ� �Դϴ�.
// STL���� �����ϴ� sort �Լ��� Ȱ���ؼ� vector<Movie>�� ������� rating ���� ������������ ���� �� �� �ֵ��� �ؾ� �մϴ�. 
class RatingSorter : public MovieProcessor {

public:
    static bool compareMovie(const Movie& a, const Movie& b) {
        return a.rating > b.rating;
    }
    void process(vector<Movie>& movies) override {
        sort(movies.begin(), movies.end(), compareMovie);

        cout << "���� ���� �������� ���ĵ� ��ȭ ���:\n";
        for (const auto& movie : movies) {
            cout << "����: " << movie.title << ", ����: " << movie.rating << "\n";
        }
    }
};

// TODO: RatingSorter Ŭ���� ����
// MovieProcessor�� ��ӹ޾� �����մϴ�.
// process �� vector<Movie>&�� ���ڷ� ������ ��ȭ����� ����Ǿ� �ֽ��ϴ�.
// process�� ���ڷ� ���� ���ʹ� ������������ �����ϰ�, ���ĵ� ��ȭ����� ����մϴ�.




// ��ü Ŭ����: Ư�� ���� �̻��� ��ȭ ���͸�
class RatingFilter : public MovieProcessor {
private:
    double minRating;

public:
    explicit RatingFilter(double minRating) : minRating(minRating) {}

    void process(vector<Movie>& movies) {
        cout << "���� " << minRating << " �̻��� ��ȭ ���:\n";
        for (const auto& movie : movies) {
            if (movie.rating >= minRating) {
                cout << "����: " << movie.title << ", ����: " << movie.rating << "\n";
            }
        }
    }
};

int main() {
    MovieManager manager;

    cout << "1. ��ȭ ��� ���\n";
    manager.printMovies();

    cout << "\n2. ��ȭ �˻� (��: Interstellar)\n";
    manager.findMovie("Interstellar");

    cout << "\n3. ���� ���� ���� �� ���\n";
    RatingSorter sorter;
    manager.processMovies(sorter);

    cout << "\n4. ���� 8.5 �̻��� ��ȭ ���͸� �� ���\n";
    RatingFilter filter(8.5);
    manager.processMovies(filter);

    return 0;
}