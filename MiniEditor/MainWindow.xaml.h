#pragma once

#include "MainWindow.g.h"

namespace winrt::MiniEditor::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        void AddOp(hstring const& name, int32_t op);
        winrt::Windows::Foundation::Collections::IVectorView<winrt::MiniEditor::OpDatWRC> GetOps();
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::MiniEditor::OpDatWRC> ops{ winrt::single_threaded_observable_vector<winrt::MiniEditor::OpDatWRC>() };

    };
}

namespace winrt::MiniEditor::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
