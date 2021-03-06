/*
    SPDX-FileCopyrightText: 1997, 1998 Lars Doelle <lars.doelle@on-line.de>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef COMPACTHISTORYSCROLL_H
#define COMPACTHISTORYSCROLL_H

// STD
#include <deque>

#include "konsoleprivate_export.h"

#include "history/HistoryScroll.h"
#include "history/compact/CompactHistoryLine.h"

namespace Konsole
{

class KONSOLEPRIVATE_EXPORT CompactHistoryScroll : public HistoryScroll
{
    typedef std::deque<std::unique_ptr<CompactHistoryLine>> HistoryArray;

public:
    explicit CompactHistoryScroll(unsigned int maxLineCount = 1000);
    ~CompactHistoryScroll() override;

    int  getLines() override;
    int  getMaxLines() override;
    int  getLineLen(int lineNumber) override;
    void getCells(int lineNumber, int startColumn, int count, Character buffer[]) override;
    bool isWrappedLine(int lineNumber) override;
    LineProperty getLineProperty(int lineNumber) override;

    void addCells(const Character a[], int count) override;
    void addCellsVector(const TextLine &cells) override;
    void addLine(LineProperty lineProperty = 0) override;

    void insertCellsVector(int position, const TextLine &cells) override;
    void insertCells(int position, const Character a[], int count) override;
    void removeCells(int position) override;

    void setMaxNbLines(unsigned int lineCount);
    void setCellsAt(int position, const Character a[], int count) override;
    void setCellsVectorAt(int position, const TextLine &cells) override;
    void setLineAt(int position, LineProperty lineProperty) override;

    int reflowLines(int columns) override;

private:
    bool hasDifferentColors(const TextLine &line) const;
    HistoryArray _lines;
    CompactHistoryBlockList _blockList;

    unsigned int _maxLineCount;
};

}

#endif
