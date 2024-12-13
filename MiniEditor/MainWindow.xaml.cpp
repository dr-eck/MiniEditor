#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::MiniEditor::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
		AddOp(L"One", 0);
		AddOp(L"Two", 1);
		AddOp(L"Three", 2);

        MEList().ItemsSource(ops);
    }
    void MainWindow::AddOp(hstring const& name, int32_t op)
    {
        // Create an instance of OpDatWRC
        winrt::MiniEditor::OpDatWRC newItem;
        newItem.opnum = ops.Size();
        newItem.name = name;
        newItem.op = op;

        // Add the new item to the IObservableVector
        ops.Append(newItem);
    }
    winrt::Windows::Foundation::Collections::IVectorView<winrt::MiniEditor::OpDatWRC> MainWindow::GetOps()
    {
        return ops.GetView();
    }
}
