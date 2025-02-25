package main

import (
	"net/http"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
	view "github.com/porfolio/packages/view"
	blogs "github.com/porfolio/packages/view/blogs"
)

func main() {
	r := chi.NewRouter()

    r.Use(middleware.Logger)

	r.Handle("/assets/*", http.StripPrefix("/assets/", http.FileServer(http.Dir("assets"))))
	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		component := view.Home()
		component.Render(r.Context(), w)
	})
	r.Get("/compliers", func(w http.ResponseWriter, r *http.Request) {
		component := blogs.Compliers()
		component.Render(r.Context(), w)
	})
	http.ListenAndServe(":3000", r)
}
