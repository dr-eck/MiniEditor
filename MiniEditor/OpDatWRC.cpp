#include "pch.h"
#include "OpDatWRC.h"
#include "OpDatWRC.g.cpp"

namespace winrt::MiniEditor::implementation
{
    void OpDatWRC::opnum(int32_t value)
    {
        if (m_opnum != value)
        {
            m_opnum = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Opnum" });
        }
    }
    void OpDatWRC::name(hstring const& value)
    {
        if (m_name != value)
        {
            m_name = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Name" });
        }
    }
    void OpDatWRC::op(int32_t value)
    {
        if (m_op != value)
        {
            m_op = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Op" });
        }
    }
    winrt::event_token OpDatWRC::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void OpDatWRC::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
