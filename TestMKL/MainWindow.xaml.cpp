#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include "mkl.h"
#include <exception>
// Standard SYCL header
//#include "compiler\2025.0\include\sycl\CL\sycl.hpp"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::TestMKL::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }
    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
        // Test MKL
        // Example: Compute the dot product of two vectors
        double x[3] = { 1.0, 2.0, 3.0 };
        double y[3] = { 4.0, 5.0, 6.0 };
        double rv;
        try {
            rv = cblas_ddot(3, x, 1, y, 1);
		}
		catch (const std::exception& e) {
			OutputDebugString((L"MKL exception: " + to_hstring(e.what()) + L"\n").c_str());
		}
        OutputDebugString((L"Dot product: " + std::to_wstring(rv) + L"\n").c_str());
        result().Text(winrt::hstring{ std::to_wstring(rv) });
    }
}
