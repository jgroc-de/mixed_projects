require "sinatra"
#require "sinatra/base"
require "sinatra/reloader" if development?
#require 'rack-flash'
require_relative "app/database"
require_relative "app/conf"
require_relative "app/helpers"
#require_relative "class"
require_relative "app/routes"
  
enable :sessions
#use Rack::Flash

#MyApp.run!
