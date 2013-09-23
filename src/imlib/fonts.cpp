/*
 *  Abuse - dark 2D side-scrolling platform game
 *  Copyright (c) 1995 Crack dot Com
 *  Copyright (c) 2005-2013 Sam Hocevar <sam@hocevar.net>
 *
 *  This software was released into the Public Domain. As with most public
 *  domain software, no warranty is made or implied by Crack dot Com, by
 *  Jonathan Clark, or by Sam Hocevar.
 */

#if defined HAVE_CONFIG_H
#   include "config.h"
#endif

#include <ctype.h>

#include "common.h"

#include "fonts.h"

void JCFont::PutString(AImage *screen, ivec2 pos, String const &st, int color)
{
    for (int i = 0; i < st.Count(); ++i, pos.x += m_size.x)
        PutChar(screen, pos, st[i], color);
}

void JCFont::PutChar(AImage *screen, ivec2 pos, char ch, int color)
{
    if (!m_data[(int)ch])
        return;

    if (color >= 0)
        m_data[(int)ch]->PutColor(screen, pos, color);
    else
        m_data[(int)ch]->PutImage(screen, pos);
}

JCFont::JCFont(AImage *letters)
{
    m_size = (letters->Size() + ivec2(1)) / ivec2(32, 8);

    AImage tmp(m_size);

    for (int ch = 0; ch < 256; ch++)
    {
        tmp.clear();
        tmp.PutPart(letters, ivec2::zero,
                    ivec2(ch % 32, ch / 32) * m_size,
                    ivec2(ch % 32 + 1, ch / 32 + 1) * m_size, 1);
        m_data[ch] = new TransImage(&tmp, "JCfont");
    }
}

JCFont::~JCFont()
{
    for (int ch = 0; ch < 256; ch++)
        delete m_data[ch];
}

