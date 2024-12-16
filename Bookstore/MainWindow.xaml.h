#pragma once
#include "MainWindow.g.h"
#include "BookstoreViewModel.h"

namespace winrt::Bookstore::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        Bookstore::BookstoreViewModel MainViewModel();

        void ClickHandler(Windows::Foundation::IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);

    private:
        Bookstore::BookstoreViewModel m_mainViewModel{ nullptr };
    };
}

namespace winrt::Bookstore::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
