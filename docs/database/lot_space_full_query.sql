SELECT * FROM lot_spaces ls
INNER JOIN vehicles v ON ls.current_vehicle_id = v.id
LEFT JOIN semi_trailers st ON v.id = st.id
LEFT JOIN reefers r ON v.id = r.trailer_id