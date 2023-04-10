#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileWorker {
private:
    static FileWorker* instance;
    FileWorker() {}

public:
    static FileWorker* getInstance() {
        if (instance == NULL) {
            instance = new FileWorker();
        }
        return instance;
    }

    void createFile(string path) {
        ofstream file(path);
        if (file) {
            cout << "File created successfully! yohooo" << endl;
            file.close();
        }
        else {
            cout << "ERROR!!!" << endl;
        }
    }

    void renameFile(string oldPath, string newPath) {
        if (rename(oldPath.c_str(), newPath.c_str()) != 0) {
            cout << "ERROR!!!" << endl;
        }
        else {
            cout << "File renamed successfully! yohooo" << endl;
        }
    }

    void deleteFile(string path) {
        if (remove(path.c_str()) != 0) {
            cout << "ERROR!!!" << endl;
        }
        else {
            cout << "File deleted successfully! yohooo" << endl;
        }
    }

    bool fileExists(string path) {
        ifstream file(path);
        return file.good();
    }
};

FileWorker* FileWorker::instance = NULL;

int main() {
    FileWorker* fileWorker1 = FileWorker::getInstance();

    fileWorker1->createFile("file1.txt");
    if (fileWorker1->fileExists("file1.txt")) {
        cout << "file1.txt exists" << endl;
    }

    fileWorker1->renameFile("file1.txt", "filenew.txt");


    fileWorker1->deleteFile("filenew.txt");
    if (!fileWorker1->fileExists("filenew.txt")) {
        cout << "filenew.txt was deleted!" << endl;
    }

    return 0;
}