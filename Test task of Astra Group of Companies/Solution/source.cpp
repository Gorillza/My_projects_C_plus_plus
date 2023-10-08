#include <QtWidgets>
#include <QFileSystemModel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv); // Создаем объект приложения

    QWidget window; // Создаем главное окно приложения
    QVBoxLayout* layout = new QVBoxLayout; // Создаем вертикальный макет для размещения виджетов

    QFileSystemModel model; // Создаем модель файловой системы
    model.setRootPath(QDir::homePath()); // Устанавливаем корневой путь модели в домашнюю директорию текущего пользователя
    model.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); // Устанавливаем фильтр для отображения всех элементов, включая скрытые файлы и папки

    QTreeView* treeView = new QTreeView; // Создаем виджет дерева для отображения файловой системы
    treeView->setModel(&model); // Связываем виджет дерева с моделью файловой системы

    QLineEdit* filterLineEdit = new QLineEdit; // Создаем виджет QLineEdit для ввода фильтра
    QObject::connect(filterLineEdit, &QLineEdit::textChanged, [&model](const QString& text) {
        model.setNameFilters(QStringList() << "*" + text + "*"); // Применяем фильтр по имени файлов и папок, основанный на введенном тексте
        model.setNameFilterDisables(false); // Отключаем автоматическое отключение фильтрации при пустом тексте
        });

    layout->addWidget(filterLineEdit); // Добавляем QLineEdit в вертикальный макет
    layout->addWidget(treeView); // Добавляем виджет дерева в вертикальный макет

    window.setLayout(layout); // Устанавливаем макет в главное окно
    window.setWindowTitle("File System Tree Viewer"); // Устанавливаем заголовок главного окна
    window.setGeometry(100, 100, 800, 600); // Устанавливаем размеры и положение главного окна
    window.show(); // Отображаем главное окно

    return app.exec(); // Запускаем цикл обработки событий приложения
}