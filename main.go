package main

import (
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
	view "github.com/porfolio/packages/view"
	"net/http"
)

func main() {
	r := chi.NewRouter()
	r.Use(middleware.Logger)
	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		component := view.Home()
		component.Render(r.Context(), w)
	})
	http.ListenAndServe(":3000", r)
}
