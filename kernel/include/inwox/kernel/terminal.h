/** MIT License
 *
 * Copyright (c) 2020 Qv Junping
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* kernel/include/inwox/kernel/terminal.h
 * Terminal class.
 */

#ifndef KERNEL_TERMINAL_H_
#define KERNEL_TERMINAL_H_

#include <inwox/kernel/keyboard.h>
#include <inwox/kernel/vnode.h>
#include <stdint.h>

#define CIRCULAR_BUFFER_SIZE 4096

typedef uint8_t color_t;

class Terminal : public Vnode, public KeyboardListener {
public:
    Terminal();
    virtual ssize_t read(void *buffer, size_t size);
    virtual ssize_t write(const void *buffer, size_t size);
    virtual void initTerminal();
    virtual void warnTerminal();
    virtual void setFontColor(color_t color);
    virtual color_t getFontColor();

private:
    virtual void onKeyboardEvent(int key);
    void writeToCircularBuffer(char c);
    char readFromCircularBuffer();

private:
    char circularBuffer[CIRCULAR_BUFFER_SIZE];
    volatile size_t readIndex;
    volatile size_t writeIndex;
};

extern Terminal terminal;

#endif /* KERNEL_TERMINAL_H_ */
