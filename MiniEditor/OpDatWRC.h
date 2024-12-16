#pragma once
#include "OpDatWRC.g.h"

namespace winrt::MiniEditor::implementation
{
    struct OpDatWRC : OpDatWRCT<OpDatWRC>
    {
		OpDatWRC() : m_opnum(0), m_name(L"BLANK"), m_op(0) {}

		int32_t opnum() { return m_opnum; }
        void opnum(int32_t value);
		hstring name() { return m_name; }
        void name(hstring const& value);
		int32_t op() { return m_op; }
        void op(int32_t value);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
		int m_opnum;
		hstring m_name;
		int m_op;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::MiniEditor::factory_implementation
{
    struct OpDatWRC : OpDatWRCT<OpDatWRC, implementation::OpDatWRC>
    {
    };
}
