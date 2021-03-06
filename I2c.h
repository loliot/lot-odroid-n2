/*
 * MIT License
 * Copyright (c) 2019-2020 Hyeonki Hong <hhk7734@gmail.com>
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

#pragma once

#include "lot-API/II2c.h"

namespace lot
{
class I2c : public II2c
{
public:
    /**
     * @brief Creates an instance of I2c class and initializes I2C.
     * @param bus_num
     */
    I2c( uint16_t bus_num );

    /**
     * @brief Creates an instance of I2c class and initializes I2C.
     * @param device Device node name.
     */
    I2c( const char *device );
    ~I2c();

    void clock( uint32_t i2c_clock ) override;

    void transmit( uint8_t  slave_address,
                   uint8_t *buffer,
                   uint16_t size ) override;
    void transmit( uint8_t slave_address, uint8_t data ) override;

    void    receive( uint8_t  slave_address,
                     uint8_t *buffer,
                     uint16_t size ) override;
    uint8_t receive( uint8_t slave_address ) override;

    void write_reg( uint8_t  slave_address,
                    uint8_t  register_address,
                    uint8_t *buffer,
                    uint16_t size ) override;
    void write_reg( uint8_t slave_address,
                    uint8_t register_address,
                    uint8_t data ) override;

    void    read_reg( uint8_t  slave_address,
                      uint8_t  register_address,
                      uint8_t *buffer,
                      uint16_t size ) override;
    uint8_t read_reg( uint8_t slave_address,
                      uint8_t register_address ) override;

private:
    char m_device[30];
    int  m_fd;

    void init( void );
};
}    // namespace lot