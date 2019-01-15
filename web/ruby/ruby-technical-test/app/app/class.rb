class MyApp < Sinatra::Base
  enable :sessions
  use Rack::Flash

  post '/set-flash' do
    # Set a flash entry
    flash[:notice] = "Thanks for signing up!"

    # Get a flash entry
    flash[:notice] # => "Thanks for signing up!"

    # Set a flash entry for only the current request
    flash.now[:notice] = "Thanks for signing up!"
  end
end
