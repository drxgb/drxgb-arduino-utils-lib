// Display.h : Representa um componente de visor
#pragma once


namespace XGB
{
    class Display :
        public DigitalComponent
    {
        Display(uint8_t pins[], uint8_t value = 0);
        Display(uint8_t pins[], uint8_t mode, uint8_t value);

    public:
        inline void begin(int mode) override
        {
            for (int i = 0; i < BCD_SEGMENTS; ++i)
            {
                pinMode(_pins[i], mode);
            }
        }

        virtual size_t pinCount() const = 0;

        uint8_t read() const = delete;
		void write(uint8_t value) = delete;

    private:
        uint8_t _pins[];
    };
}