/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef SFTPDEFS_H
#define SFTPDEFS_H

#include "ssh_global.h"

#include <QFile>
#include <QString>

namespace QSsh {

typedef quint32 SftpJobId;
QSSH_EXPORT extern const SftpJobId SftpInvalidJob;

enum SftpOverwriteMode {
    SftpOverwriteExisting, SftpAppendToExisting, SftpSkipExisting
};

enum SftpFileType { FileTypeRegular, FileTypeDirectory, FileTypeOther, FileTypeUnknown };

class QSSH_EXPORT SftpFileInfo
{
public:
    SftpFileInfo() : type(FileTypeUnknown), sizeValid(false), permissionsValid(false) { }

    QString name;
    SftpFileType type;
    quint64 size;
    QFile::Permissions permissions;
    
    //add by hadesjaky 2017.7.2 add file time
    quint32 atime;
    quint32 mtime;//modify time    

    // The RFC allows an SFTP server not to support any file attributes beyond the name.
    bool sizeValid;
    bool permissionsValid;
};

} // namespace QSsh

#endif // SFTPDEFS_H
