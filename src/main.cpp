/**
 * @file main.cpp
 * @brief Entry point for the Lot Manager application.
 */
#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

/**
 * @brief Application entry point.
 * @param argc Command line argument count.
 * @param argv Command line argument vector.
 * @return Exit code of the application (0 for success, otherwise for error).
 */
auto main(int argc, char *argv[]) -> int {
  QApplication app(argc, argv);

  QTranslator translator;
  const QStringList ui_languages = QLocale::system().uiLanguages();
  for (const QString &locale : ui_languages) {
    const QString base_name = "lot-manager_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + base_name)) {
      QApplication::installTranslator(&translator);
      break;
    }
  }

  MainWindow window;
  window.show();
  return QApplication::exec();
}
