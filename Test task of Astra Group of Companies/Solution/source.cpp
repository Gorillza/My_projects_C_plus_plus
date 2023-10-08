#include <QtWidgets>
#include <QFileSystemModel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv); // ������� ������ ����������

    QWidget window; // ������� ������� ���� ����������
    QVBoxLayout* layout = new QVBoxLayout; // ������� ������������ ����� ��� ���������� ��������

    QFileSystemModel model; // ������� ������ �������� �������
    model.setRootPath(QDir::homePath()); // ������������� �������� ���� ������ � �������� ���������� �������� ������������
    model.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); // ������������� ������ ��� ����������� ���� ���������, ������� ������� ����� � �����

    QTreeView* treeView = new QTreeView; // ������� ������ ������ ��� ����������� �������� �������
    treeView->setModel(&model); // ��������� ������ ������ � ������� �������� �������

    QLineEdit* filterLineEdit = new QLineEdit; // ������� ������ QLineEdit ��� ����� �������
    QObject::connect(filterLineEdit, &QLineEdit::textChanged, [&model](const QString& text) {
        model.setNameFilters(QStringList() << "*" + text + "*"); // ��������� ������ �� ����� ������ � �����, ���������� �� ��������� ������
        model.setNameFilterDisables(false); // ��������� �������������� ���������� ���������� ��� ������ ������
        });

    layout->addWidget(filterLineEdit); // ��������� QLineEdit � ������������ �����
    layout->addWidget(treeView); // ��������� ������ ������ � ������������ �����

    window.setLayout(layout); // ������������� ����� � ������� ����
    window.setWindowTitle("File System Tree Viewer"); // ������������� ��������� �������� ����
    window.setGeometry(100, 100, 800, 600); // ������������� ������� � ��������� �������� ����
    window.show(); // ���������� ������� ����

    return app.exec(); // ��������� ���� ��������� ������� ����������
}