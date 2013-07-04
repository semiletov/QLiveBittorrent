#ifndef SEEDMANAGER_H
#define SEEDMANAGER_H

#include <QObject>
#include <QString>
#include <QFileInfoList>
#include <QDir>
#include <QDebug>
#include <QTimer>
#include <QApplication>
#include <QSettings>
#include <QSet>

#include <curses.h>
#include <map>
#include <iostream>

#include <constants.h>

#include <libtorrent/session.hpp>
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/entry.hpp>
#include <libtorrent/alert_types.hpp>
#include <libtorrent/bencode.hpp>

using libtorrent::add_torrent_params;
using libtorrent::torrent_info;
using libtorrent::torrent_status;
using libtorrent::torrent_handle;
using libtorrent::entry;
using libtorrent::alert;

class SeedManager : public QObject
{
    Q_OBJECT
public:
    explicit SeedManager(QObject *parent = 0);
    ~SeedManager();

private:
    libtorrent::session *session;
    std::map<std::string, QString> torrentNames;
    QSet<QString> s;

    void addTorrent(QString);
private slots:
    void updateInform();
    void checkForErrors();
    void findTorrents();
};

#endif // SEEDMANAGER_H
