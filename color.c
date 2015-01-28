/* $Id$ */
/*
 * Copyright (c) 2015 Dimitri Sokolyuk <demon@dim13.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include "color.h"

struct color
newcolor(long n)
{
	struct color c;

	c.r = n >> 0x10;
	c.g = n >> 0x08;
	c.b = n;

	return c;
}

struct color
shade(struct color c)
{
	c.r >>= 2;
	c.g >>= 2;
	c.b >>= 2;

	return c;
}

struct color
tint(struct color c)
{
	c.r += (0xFF - c.r) >> 1;
	c.g += (0xFF - c.g) >> 1;
	c.b += (0xFF - c.b) >> 1;

	return c;
}

char *
string(struct color c)
{
	char *ret;

	asprintf(&ret, "#%.2x%.2x%.2x", c.r, c.g, c.b);

	return ret;
}
